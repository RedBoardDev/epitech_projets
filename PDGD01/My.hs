{-
-- EPITECH PROJECT, 2022
-- PDGD01
-- File description:
-- My.hs
-}

mySucc :: Int -> Int
mySucc var = var + 1

myIsNeg :: Int -> Bool
myIsNeg var
    | var >= 0 = False
    | otherwise = True

myAbs :: Int -> Int
myAbs var
    | var >= 0 = var
    | otherwise = var * (-1)

myMin :: Int -> Int -> Int
myMin var1 var2
    | var1 < var2 = var1
    | otherwise = var2

myMax :: Int -> Int -> Int
myMax var1 var2
    | var1 < var2 = var2
    | otherwise = var1

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (x, _) = x

mySnd :: (a, b) -> b
mySnd (_, x) = x

mySwap :: (a, b) -> (b, a)
mySwap (var1, var2) = (var2, var1)

myHead :: [a] -> a
myHead [] = error "Empty list"
myHead (x:_) = x

myTail :: [a] -> [a]
myTail [] = error "Empty list"
myTail (_:a) = (a)

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] _ = error "Empty list"
myNth list i
    | i > myLength(list) || i < 0  = error "Error on the list"
myNth (x:xs) i
    | i > 0 = myNth(xs)(i - 1)
    | otherwise = x

myTake :: Int -> [a] -> [a]
myTake _ [] = error "Empty list"
myTake 0 _ = []
myTake i list
    | i >= myLength(list) || i < 0 = list
myTake i (x:xs) = x : myTake(i - 1)(xs)

myDrop :: Int -> [a] -> [a]
myDrop _ [] = error "Empty list"
myDrop i list
    | i >= myLength(list) = []
    | i <= 0 = list
myDrop i (x:xs) = myDrop(i - 1)(xs)

myLast :: [a] -> a
myLast [] = error "Empty list"
myLast (x:xs)
    | myLength(xs) > 0 = myLast(xs)
    | otherwise = x

myAppend :: [a] -> [a] -> [a]
myAppend a1 [] = a1
myAppend [] a2 = a2
myAppend (x1:xs1) a2
    | myLength(xs1) >= 0 = x1 : myAppend(xs1)(a2)
myAppend _ a2 = a2

myInit :: [a] -> [a]
myInit [] = error "Empty list"
myInit a1 = myTake(myLength(a1) - 1)(a1)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse a1 = myLast(a1) : myReverse(myInit(a1))

myZip :: [a] -> [b] -> [(a,b)]
myZip a1 a2
    | myLength(a2) >= myLength(a1) && myLength(a1) == 0 = []
    | myLength(a2) < myLength(a1) && myLength(a2) == 0 = []
myZip (x1:xs1) (x2:xs2) = (x1,x2) : myZip(xs1)(xs2)

getLastCp :: [(a, b)] -> [(a, b)]
getLastCp (x: xs) = xs

setListA :: [(a, b)] -> [a]
setListA [] = []
setListA a1 = myFst(myHead(a1)) : setListA(getLastCp(a1))

setListB :: [(a, b)] -> [b]
setListB [] = []
setListB a1 = mySnd(myHead(a1)) : setListB(getLastCp(a1))

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip a1 = (setListA(a1), setListB(a1))

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap fct (x:xs) = fct(x) : myMap(fct)(xs)

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter fct (x:xs)
    | fct(x) == True = x : myFilter fct(xs)
    | otherwise = myFilter fct(xs)
