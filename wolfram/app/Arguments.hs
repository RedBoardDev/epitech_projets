{-
-- EPITECH PROJECT, 2022
-- B-FUN-400-MLH-4-1-wolfram-thomas.ott
-- File description:
-- Arguments.hs
-}

module Arguments (
  setArgsOnTuple,
  createBaseListArgs,
  addNodeOnListOfTuple,
  getNbrLines,
  getRuleNbr,
  getStartNbr,
  getMoveNbr,
  getWindowSize
) where

-- NUMBERS CONVERTOR
readNegativeInt :: String -> Int
readNegativeInt [] = 0
readNegativeInt (_:xs) = (read xs::Int) * (-1)

readInt :: String -> Int
readInt a
  | head a == '-' = readNegativeInt a
  | otherwise = read a::Int

-- STORE ARGUMENTS

createBaseListArgs :: [(String, Int)]
createBaseListArgs = [("--start", 0), ("--window", 80
                    ), ("--move", 0), ("--lines", -1)]

addNodeOnListOfTuple :: (String, Int) -> [(String, Int)] -> [(String, Int)]
addNodeOnListOfTuple x1 x2 = [x1] ++ x2

setArgsOnTuple :: [(String, Int)] -> [String] -> [(String, Int)]
setArgsOnTuple x1 [] = x1
setArgsOnTuple x1 (x:s:xs) = setArgsOnTuple (addNodeOnListOfTuple (x,
                            readInt (s)) (x1)) (xs)
setArgsOnTuple _ _ = [("--start", 0), ("--window", 80), ("--move", 0)]

-- PARSING

getWindowSize :: [(String, Int)] -> Int
getWindowSize args = getValueOnTuple ("--window") (args)

getMoveNbr :: [(String, Int)] -> Int
getMoveNbr args = getValueOnTuple ("--move") (args)

getNbrLines :: [(String, Int)] -> Int
getNbrLines args = getValueOnTuple ("--lines") (args)

getStartNbr :: [(String, Int)] -> Int
getStartNbr args = getValueOnTuple ("--start") (args)

getRuleNbr :: [(String, Int)] -> Int
getRuleNbr args = getValueOnTuple ("--rule") (args)

getValueOnTuple :: String -> [(String, Int)] -> Int
getValueOnTuple _ [] = 0
getValueOnTuple key ((x, s): xs)
  | key == x = s
  | otherwise = getValueOnTuple (key) (xs)
