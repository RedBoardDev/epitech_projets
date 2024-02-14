{-
-- EPITECH PROJECT, 2022
-- oui
-- File description:
-- oui
-}

module ErrorHandlings (checkIfArgsGood) where
import Text.Read (readMaybe)

isFloat :: String -> Bool
isFloat nbr = Nothing /= (readMaybe nbr :: Maybe Float)

isInt :: String -> Bool
isInt nbr = Nothing /= (readMaybe nbr :: Maybe Int)

checkFlagArg :: String -> String -> Int -> Int
checkFlagArg "-n" nbr check
    | isInt (nbr) = (check + 1)
    | otherwise = -1
checkFlagArg "-l" nbr check
    | isFloat (nbr) = (check + 1)
    | otherwise = -1
checkFlagArg "-f" _ check = (check + 1)
checkFlagArg _ _ _ = -1

checkArgs :: [String] -> Int -> Bool
checkArgs _ (-1) = False
checkArgs [] check
    | (check >= 3) = True
    | otherwise = False
checkArgs (x:s:xs) check = checkArgs (xs) (checkFlagArg (x) (s) (check))
checkArgs _ _ = False

checkIfArgsGood :: [String] -> Bool
checkIfArgsGood [] = False
checkIfArgsGood args
    | checkArgs (args) (0) = True
    | otherwise = False
