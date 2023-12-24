local function exists(v, t)
	for e,n in pairs(t) do
		if e == v then
			return true
		end
	end
	return false
end
message = ""

linelen = 8

for i = 1, linelen do
	--print(i)
	chars = {}
	letters = 0
	for line in io.lines("input.txt") do
		c = string.sub(line, i, i)
		if exists(c, chars) then
			chars[c] = chars[c] + 1
		else
			chars[c] = 1
			letters = letters + 1
		end
	end
	local sorted = {}
	for k, v in pairs(chars) do
		table.insert(sorted, {k, v})
	end
	table.sort(sorted, function(a,b) 
		return a[2] < b[2] end)
	for _, v in ipairs(sorted) do
		print(v[1])
		break
	end
end

print(message)
