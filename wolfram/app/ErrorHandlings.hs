{-
-- EPITECH PROJECT, 2022
-- B-FUN-400-MLH-4-1-wolfram-thomas.ott
-- File description:
-- errorHandlings.hs
-}

module ErrorHandlings (checkIfGood, checkMandatoryRule) where

-- ERROR HANDLINGS

charIsDigit :: Char -> Bool
charIsDigit a
  | a >= '0' && a <= '9' = True
  | otherwise = False

stringIsDigitRec :: String -> Bool
stringIsDigitRec [] = True
stringIsDigitRec (x:xs)
  | charIsDigit x = stringIsDigitRec (xs)
  | otherwise = False

stringIsDigit :: String -> Bool
stringIsDigit [] = False
stringIsDigit ('-':xs) = stringIsDigitRec (xs)
stringIsDigit s = stringIsDigitRec (s)

checkArgString :: String -> Int
checkArgString "--rule" = 1
checkArgString "--start" = 2
checkArgString "--lines" = 3
checkArgString "--window" = 4
checkArgString "--move" = 5
checkArgString _ = 0

checkArgs :: [String] -> Bool
checkArgs [] = True
checkArgs (x:s:xs)
  | checkArgString (x) /= 0 && stringIsDigit (s) == True = checkArgs (xs)
  | otherwise = False
checkArgs _ = False

checkIfGood :: [String] -> Bool
checkIfGood [] = False
checkIfGood args
  | checkArgs (args) = True
  | otherwise = False

compareMandatoryRule :: String -> Int -> Bool
compareMandatoryRule "--rule" i
  | i >= 0 && i <= 255 = True
compareMandatoryRule _ _ = False

checkMandatoryRule :: [String] -> Bool
checkMandatoryRule [] = False
checkMandatoryRule (x:s:xs)
  | compareMandatoryRule (x) (read (s)) == False = checkMandatoryRule (xs)
  | otherwise = True
checkMandatoryRule _ = False
