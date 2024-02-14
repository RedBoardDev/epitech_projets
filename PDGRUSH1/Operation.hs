{-
-- EPITECH PROJECT, 2022
-- B-PDG-300-MLH-3-1-PDGRUSH1-martin.d-herouville
-- File description:
-- operation.hs
-}

module Operation where

mySa :: [l_a] -> [l_a]
mySa [] = []
mySa [x] = [x]
mySa (x:y:xs) = y:x:xs

mySb :: [l_b] -> [l_b]
mySb [] = []
mySb [x] = [x]
mySb (x:y:xs) = y:x:xs

mySc :: ([l_a], [l_b]) -> ([l_a], [l_b])
mySc (x, y) = (mySa(x), mySb(y))

myPa :: ([l_a], [l_a]) -> ([l_a], [l_a])
myPa (x, []) = (x, [])
myPa (x1, x2:xs2) = (x2 : x1, xs2)

myPb :: ([l_a], [l_a]) -> ([l_a], [l_a])
myPb ([], x) = ([], x)
myPb (a:as, b) = (as, a : b)

myRra :: [l_a] -> [l_a]
myRra [] = []
myRra [a] = [a]
myRra (x1:xs1) = (([last(xs1)] ++ [x1]
    ++ take(length(xs1) - 1)(xs1)))

myRrb :: [l_a] -> [l_a]
myRrb [] = []
myRrb [a] = [a]
myRrb (x2:xs2) = ([last(xs2)]
    ++ [x2] ++ take(length(xs2) - 1)(xs2))

myRrr :: ([l_a], [l_a]) -> ([l_a], [l_a])
myRrr (x, y) = (myRra x, myRrb y)

myRb :: [l_a] -> [l_a]
myRb [] = []
myRb (x:xs) = xs ++ [x]

myRa :: [l_a] -> [l_a]
myRa [] = []
myRa (x:xs) = xs ++ [x]

myRr :: ([l_a], [l_a]) -> ([l_a], [l_a])
myRr (x, y) = (myRa x, myRb y)
