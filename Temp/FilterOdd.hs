filterOdd :: Int -> [Int] -> [Int]
filterOdd n []          = []
filterOdd n (x:xs) 
    | n `rem` 2 == 0    = filterOdd (n+1) xs
    | otherwise         = [x] ++ filterOdd (n+1) xs

f :: [Int] -> [Int]
f xs = filterOdd 0 xs
