{-
-- EPITECH PROJECT, 2022
-- B-PDG-300-MLH-3-1-PDGRUSH1-martin.d-herouville
-- File description:
-- Main.hs
-}

module Main where

import System.Environment
import System.Exit
import Operation

-- INSTRUCTIONS PARSING
getStringUntilSpace :: String -> String
getStringUntilSpace "" = ""
getStringUntilSpace (x:xs)
    | x /= ' ' = x : getStringUntilSpace xs
    | otherwise = ""

getStringAfterSpace :: String -> String
getStringAfterSpace "" = ""
getStringAfterSpace (' ':xs) = xs
getStringAfterSpace (_:xs) = getStringAfterSpace xs

stringToList :: String -> [String]
stringToList "" = []
stringToList s = [getStringUntilSpace s] ++ stringToList(getStringAfterSpace s)

-- INSTRUCTIONS ERROR HANDLING
checkInstruction :: String -> Bool
checkInstruction "sa" = True
checkInstruction "sb" = True
checkInstruction "sc" = True
checkInstruction "pa" = True
checkInstruction "pb" = True
checkInstruction "ra" = True
checkInstruction "rb" = True
checkInstruction "rr" = True
checkInstruction "rra" = True
checkInstruction "rrb" = True
checkInstruction "rrr" = True
checkInstruction _ = False

checkInstructions :: [String] -> Bool
checkInstructions [] = True
checkInstructions (x:xs)
    | checkInstruction x = checkInstructions xs
    | otherwise = False

-- NUMBERS PARSING
readNegativeInt :: String -> Int
readNegativeInt (x:xs) = (read xs::Int) * (-1)

readInt :: String -> Int
readInt a
    | head a == '-' = readNegativeInt a
    | otherwise = read a::Int

mapInt :: (String -> Int) -> [String] -> [Int]
mapInt _ [] = []
mapInt f (x:xs) = [f x] ++ mapInt f xs

-- NUMBERS ERROR HANDLING
charIsDigit :: Char -> Bool
charIsDigit a
    | a >= '0' && a <= '9' = True
    | otherwise = False

stringIsDigitRec :: String -> Bool
stringIsDigitRec [] = True
stringIsDigitRec (x:xs)
    | charIsDigit x = stringIsDigitRec xs
    | otherwise = False

stringIsDigit :: String -> Bool
stringIsDigit [] = False
stringIsDigit ('-':xs) = stringIsDigitRec xs
stringIsDigit s = stringIsDigitRec s

checkNumbers :: [String] -> Bool
checkNumbers [] = True
checkNumbers (x:xs)
    | stringIsDigit x = checkNumbers xs
    | otherwise = False

-- GLOBAL ERROR HANDLING
checkIfInputOk :: [String] -> [String] -> Bool
checkIfInputOk [] _ = False
checkIfInputOk numbers instructions
    | checkNumbers numbers && checkInstructions instructions = True
    | otherwise = False

safeLast :: [a] -> Maybe a
safeLast [] = Nothing
safeLast a = Just(last a)

-- SORTING ALGO
switchInstructions :: String -> ([Int], [Int]) -> ([Int], [Int])
switchInstructions "sa" (x1, x2) = (mySa x1, x2)
switchInstructions "sb" (x1, x2) = (x1, mySb x2)
switchInstructions "sc" t = mySc t
switchInstructions "pa" t = myPa t
switchInstructions "pb" t = myPb t
switchInstructions "ra" (x1, x2) = (myRa x1, x2)
switchInstructions "rb" (x1, x2) = (x1, myRb x2)
switchInstructions "rr" t = myRr t
switchInstructions "rra" (x1, x2) = (myRra x1, x2)
switchInstructions "rrb" (x1, x2) = (x1, myRrb x2)
switchInstructions "rrr" t = myRrr t
switchInstructions _ t = t

sortInput :: [String] -> ([Int], [Int]) -> ([Int], [Int])
sortInput [] t = t
sortInput (x:xs) t = sortInput xs (switchInstructions x t)

-- END CHECK
sorted :: (Ord a) => [a] -> Bool
sorted [] = True
sorted [x] = True
sorted (x:y:xs)
    | x <= y = sorted (y:xs)
    | otherwise = False

printResult :: ([Int], [Int]) -> IO ()
printResult all@(_, (_:_)) = putStr("KO: ") >> print all
printResult all@(a1, a2)
    | sorted(a1) == True = putStrLn("OK")
    | otherwise = putStr("KO: ") >> print all

-- MAIN
main :: IO ()
main = do
    instructions <- getLine
    numbers <- getArgs
    if safeLast instructions == Just ' ' ||
        checkIfInputOk numbers (stringToList instructions) == False then
        exitWith(ExitFailure 84)
    else
        printResult(sortInput(stringToList instructions)
        (mapInt readInt numbers, []))
