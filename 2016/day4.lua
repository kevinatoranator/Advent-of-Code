
local function exists(v, t)
	for e,n in pairs(t) do
		if e == v then
			return true
		end
	end
	return false
end

sum = 0

for line in io.lines("input.txt") do
	letters = {}
	pattern = line:match("%[(%a+)%]")
	id = line:match("%d+")
	print(pattern)
	line = line:gsub("-", "")
	line = line:match("%a+")
	print(line)
	for c in line:gmatch"." do
		if c == "[" then
			break
		elseif exists(c, letters) then
			letters[c] = letters[c] + 1
		else
			letters[c] = 1
		end
	end
	
	local sorted = {}
	for k, v in pairs(letters) do
		table.insert(sorted, {k, v})
	end
	
	table.sort(sorted, function(a,b) 
		if a[2] == b[2] then
			return a[1] < b[1]
		end
		return a[2] > b[2]
	end)
	--for _, v in ipairs(sorted) do
		--print(v[1], v[2])
	--end
	
	sstring = sorted[1][1]..sorted[2][1]..sorted[3][1]..sorted[4][1]..sorted[5][1]
	if sstring == pattern then
		sum = sum + id
	end
end

print(sum)
