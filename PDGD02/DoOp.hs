{-
-- EPITECH PROJECT, 2022
-- B-PDG-300-MLH-3-1-PDGD02-thomas.ott
-- File description:
-- DoOp.hs
-}

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs

myHead :: [a] -> a
myHead [] = error "Empty list"
myHead (x:_) = x

myCorp :: [a] -> [a]
myCorp [] = error "Empty list"
myCorp (x:xs) = xs

myFst :: (a, b) -> a
myFst (x, _) = x

mySnd :: (a, b) -> b
mySnd (_, x) = x

myAppend :: [a] -> [a] -> [a]
myAppend a1 [] = a1
myAppend [] a2 = a2
myAppend (x1:xs1) a2
    | myLength(xs1) >= 0 = x1 : myAppend(xs1)(a2)
myAppend _ a2 = a2

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem nbr (x:xs)
    | nbr == x = True
    | otherwise = myElem(nbr)(xs)

safeDiv :: Int -> Int -> Maybe Int
safeDiv 0 _ = Nothing
safeDiv _ 0 = Nothing
safeDiv i1 i2 = Just (i1 `div` i2)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth list i
    | i > myLength(list) || i < 0  = Nothing
safeNth (x:xs) i
    | i > 0 = safeNth(xs)(i - 1)
    | otherwise = Just x

safeSucc :: Maybe Int -> Maybe Int
safeSucc i = fmap(+ 1) i

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup i (x1:x2)
    | myFst(x1) == i = Just (mySnd(x1))
    | otherwise = myLookup(i)(x2)

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo fct (Just a) (Just b) = Just (fct a b)

checkInt :: [Char] -> Bool
checkInt [] = True
checkInt c
    | myHead(c) >= '0' && myHead(c) <= '9' = checkInt (myCorp(c))
    | myHead(c) == '-' = checkInt (myCorp(c))
    | otherwise  = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt c
    | checkInt(c) == False = Nothing
    | otherwise = Just (read c)

getLineLength :: IO Int
getLineLength = do
    x <- getLine
    return (myLength(x))

printAndGetLength :: String -> IO Int
printAndGetLength d = putStrLn (d) >> return (myLength(d))

putFullLine :: Int -> Bool -> IO ()
putFullLine 0 _ = return ()
putFullLine i True
    | i > 0 = putStr ("-") >> putFullLine (i - 1)(True)
putFullLine i False
    | i > 0 = putStr (" ") >> putFullLine (i - 1)(False)

putMiddleLine :: Int -> Int -> IO ()
putMiddleLine 2 _ = return ()
putMiddleLine i nbr
    | i > 2 = putStr ("|") >> putFullLine(nbr)(False)
    >> putStrLn("|") >> putMiddleLine(i - 1)(nbr)

putSectionLine :: Int -> Int -> IO ()
putSectionLine i nbr = putStr ("+")
    >> putFullLine(nbr - 2)(True) >> putStrLn ("+")

printBox :: Int -> IO ()
printBox 1 = putSectionLine(1)(2) >> return ()
printBox i
    | i <= 0 = return ()
printBox i = putSectionLine(i)(i * 2)
    >> putMiddleLine(i)((i * 2) - 2) >> putSectionLine(i)(i * 2)

concatLines :: Int -> IO String
concatLines a
    | a <= 0 = return ""
concatLines nbr = do
    x <- getLine
    y <- concatLines(nbr - 1)
    return (x ++ y)

getInt :: IO (Maybe Int)
getInt = do
    x <- getLine
    return (readInt(x))
