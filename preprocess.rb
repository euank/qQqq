require 'json'

fin = File.read('q.c')
tokens = fin.split(/\s+/)

tokens.reject!{|t| t[0] == '#' || t =~ /\"|\'/}

frequency = tokens.each_with_object(Hash.new(0)) { |o,h| h[o] += 1 }.to_a

chars = ['q', 'Q']

perms = []
i = 1

while perms.size < frequency.size do
  perms << chars.repeated_permutation(i).map(&:join)
  i += 1
  perms = perms.flatten
end
frequency = frequency.sort_by{|x| x[1]}.reverse

tokens = frequency.zip(perms)

out = ''

tokens.each do |token|
  text = token[0][0]

  define = token[1]

  out += "#define #{define} #{text}\n"
  fin.gsub!(/(\s+)#{Regexp.escape(text)}(\s+)/, '\1' + define + '\2')
end

File.write("qQqq.c", out + "\n" + fin)

