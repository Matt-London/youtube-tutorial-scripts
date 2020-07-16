SIZE = 10000

toSort = Array.new(SIZE, 0)

def build(l)
  i = 0
  num = SIZE
  while i < SIZE
    l[i] = num
    num -= 1
    i += 1
  end
end

def sort(l)
  sorted = false
  until sorted
    sorted = true
    i = 0
    while i < SIZE - 1
      if l[i] > l[i + 1]
        temp = l[i + 1]
        l[i + 1] = l[i]
        l[i] = temp
        sorted = false
      end
      i += 1
    end
  end
end

build(toSort)
sort(toSort)
