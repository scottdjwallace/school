-- The value size is an Int, defined to be
-- the sum of twelve and thirteen.

size :: Int
size = 12+13

-- The function to sqaure an Int

square :: Int -> Int
square n = n*n

-- The function to double an Int

double :: Int -> Int
double n = 2*n

-- An example using double, square, and size

example :: Int
example = double (size - sqaure (2+2))