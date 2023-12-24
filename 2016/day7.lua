sum = 0

local function stringCheck(strs)
	abba = false
	for str in strs do
		bchar = 1
		--print(str)
		for ch in str:gmatch"." do
			substr = string.sub(str, bchar, bchar + 3)
			--print(substr)
			b1 = string.sub(substr, 2, 2)
			b2 = string.sub(substr, 3, 3)
			b3 = string.sub(substr, 4, 4)
			--print(ch, b1, b2, b3)
			--print(#substr)
			if ch == b3 and b1 == b2 and ch ~= b1 and #substr == 4 then
				--print("abba found")
				--print(ch, b1, b2, b3)
				abba = true
			end
			bchar = bchar + 1
		end
	end
	return abba
end

local function isSSL(abas, bk)
	ssl = false
	for n,aba in pairs(abas) do
		b1 = string.sub(aba, 1, 1)
		b2 = string.sub(aba, 2, 2)
		bab = b2 .. b1 .. b2
	--	print("bab is", bab)
		for n,b in pairs(bk) do
			--print(b)
			if string.find(b, bab) ~= nil then
	--			print(bab, "valid")
				ssl = true
			end
		end
	end
	return ssl
end

local function findABA(strs)
	aba = {}
	for str in strs do
		bchar = 1
		--print(str)
		for ch in str:gmatch"." do
			substr = string.sub(str, bchar, bchar + 2)
			--print(substr)
			b1 = string.sub(substr, 2, 2)
			b2 = string.sub(substr, 3, 3)
			--print(ch, b1, b2, b3)
			--print(#substr)
			if ch == b2 and ch ~= b1 and #substr == 3 then
				--print("abba found")
				--print(ch, b1, b2, b3)
				--print(substr)
				table.insert(aba, substr)
			end
			bchar = bchar + 1
		end
	end
	--for n,str in pairs(aba) do
	--	print(str)
	--end
	return aba
end

for line in io.lines("input.txt") do
	fcheck = line:gmatch("(%a+)%[")
	lcheck = line:gmatch("%](%a+)")
	mcheck = line:gmatch("%](%a+)%[")
	brackets = line:gmatch("%[(%a+)%]")
	--print(lcheck)
	--fvalid = stringCheck(fcheck)
	--lvalid = stringCheck(lcheck)
	--mvalid = stringCheck(mcheck)
	--bvalid = stringCheck(bracket)
	abaf = findABA(fcheck)
	abal = findABA(lcheck)
	abam = findABA(mcheck)
	bracket = {}
	for b in brackets do
		table.insert(bracket, b)
	end
	--for n,str in pairs(abaf) do
	--	print(str)
	--end
	if isSSL(abaf, bracket) or isSSL(abal, bracket) or isSSL(abam, bracket) then
		sum = sum + 1
	end
	--print (fvalid, lvalid, mvalid, ":", bvalid)
	--if (fvalid or lvalid or mvalid) and not bvalid then
	--	print("valid")
		--sum = sum + 1
	--else
	--	print("invalid")
	--end
	--print()
end


print(sum)
