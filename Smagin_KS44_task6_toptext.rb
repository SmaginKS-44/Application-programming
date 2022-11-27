def main
    str = "e e e e DDD ddd DdD: ddd ddd aa aA Aa, bb cc cC e e e"
    nstr = noSpace(str.downcase)
    hs = getHashWord(nstr)
    res = getTop3(hs)
    print res
end

def noSpace(str)
    str.split(/[^[[:word:]'-]]/)
end

def getHashWord(str)
    hash = Hash.new
    i = 0
    while i < str.length do
        word = str[i]
        if word.length != 0 || !hash.include?(word)
            hash[word] = str.count(word)
        end
        i += 1
    end
    hash
end

def getTop3(hs)
    top3 = hs.sort_by {|k, v| v}.to_h.keys.reverse
    top3[0..2]
end

main()