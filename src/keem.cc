#include <json.hpp>
#include <regex>
#include <stdio.h>
#include <string>
#include <workflow/HttpMessage.h>
#include <workflow/WFHttpServer.h>

using json = nlohmann::json;

const std::regex kRpcRegex("^(\\/rpc\\/)([A-z]+)$");

void json_response(protocol::HttpResponse *http_resp, json data,
                   int status_code) {
  http_resp->set_status_code(std::to_string(status_code));
  http_resp->append_output_body(data.dump().c_str());

  // can we reuse this?
  protocol::HttpMessageHeader header;
  header.name = "Content-Type";
  header.value = "application/json";

  http_resp->set_header(&header);
}

int main(void) {
  WFHttpServer server([](WFHttpTask *task) {
    std::string path = std::string(task->get_req()->get_request_uri());

    std::smatch match;
    if (!std::regex_match(path, match, kRpcRegex)) {
      json_response(task->get_resp(),
                    json({{"code", 404}, {"error", "Resource Not Found"}}),
                    404);
      return;
    }
  });

  int error;
  if ((error = server.start(8080)) == 0) {
    // stops server when any key + enter is pressed
    getchar();
    server.stop();
  } else {
    fprintf(stderr, "error: code %d\n", error);
  }

  return 0;
}
