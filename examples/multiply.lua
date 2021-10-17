local function execute(data)
	-- assert(type(data) == 'table', 'expected data to be a table')

	assert(data['a'] ~= nil, 'expected "a"')
	assert(data['b'] ~= nil, 'expected "b"')

	assert(type(data['a']) == 'number', 'expected "a" to be a number')
	assert(type(data['b']) == 'number', 'expected "b" to be a number')

	return data['a'] * data['b']
end

local options = {
	name = 'multiply',
	method = 'POST',
}

return {
	options = options,
	execute = execute,
}
