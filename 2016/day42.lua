
local function exists(v, t)
	for e,n in pairs(t) do
		if e == v then
			return true
		end
	end
	return false
end

local function cypher(ch, shft)
	alphabet = 'abcdefghijklmnopqrstuvwxyz'
	index = alphabet:find(ch)
	if index then
		index = (index + shft) % #alphabet
	end
	if index == 0 then
		newCh = 'z'
	else
		newCh = alphabet:sub(index, index)
	end
	return newCh
end

sum = 0

for line in io.lines("input.txt") do
	letters = {}
	pattern = line:match("%[(%a+)%]")
	id = line:match("%d+")
	--print(pattern)
	original = line:match("(.+)-%d")
	--print(original)
	line = line:gsub("-", "")
	line = line:match("%a+")
	--print(line)
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


	newString = ""
	for ch in original:gmatch(".") do
		if ch == "-" then
			newString = newString .. " "
		else
			ch = cypher(ch, id)
			newString = newString .. ch
		end
	end
	--print(newString)
	if string.find(newString, "storage") then
		print(newString ,id)
		sum = id
	end
end

print(sum)
