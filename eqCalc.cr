# Grab the points
print "X1: "
xone = gets.not_nil!.chomp.to_f

print "Y1: "
yone = gets.not_nil!.chomp.to_f

print "X2: "
xtwo = gets.not_nil!.chomp.to_f

print "Y2: "
ytwo = gets.not_nil!.chomp.to_f

# error checking
if xone == xtwo && yone == ytwo
  puts "Please enter two different points"
  exit
elsif xone == xtwo
  puts "x = #{xone}"
  exit
elsif yone == ytwo
  puts "y = #{yone}"
  exit
end

# Do the math
m = (ytwo - yone) / (xtwo - xone)

b = ytwo - m * xtwo

# round
m = m.round(3)
b = b.round(3)

# output equation
if b > 0
  puts "y = #{m}x + #{b}"
elsif b < 0
  puts "y = #{m}x - #{b * -1}"
else
  puts "y = #{m}x"
end

# puts "(#{xone}, #{yone})\n(#{xtwo}, #{ytwo})"
