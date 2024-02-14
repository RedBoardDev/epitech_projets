{-
-- EPITECH PROJECT, 2022
-- B-FUN-400-MLH-4-1-wolfram-thomas.ott
-- File description:
-- Main.hs
-}

module Main (main) where
import ErrorHandlings (checkIfGood, checkMandatoryRule)
import Arguments (
  setArgsOnTuple,
  createBaseListArgs,
  addNodeOnListOfTuple,
  getNbrLines,
  getRuleNbr,
  getStartNbr,
  getMoveNbr,
  getWindowSize)
import GeneratorLine (createFirstLine, createNextLine)
import System.Environment (getArgs)
import System.Exit

-- MAIN FUNCTION

removeFirstAndLastChar :: String -> String
removeFirstAndLastChar str = init(tail str)

removeCharOnString :: Int -> String -> String
removeCharOnString n str
  | n < 0 = str
  | otherwise = removeCharOnString (n - 2) (removeFirstAndLastChar (str))

printLine :: Int -> Int -> [(String, Int)] -> String -> IO ()
printLine charNotPrinted i args actualLine
  | i >= (getNbrLines args) && (getNbrLines args) /= -1 = return ()
  | getStartNbr (args) > 0 = printLine (length (actualLine) - getWindowSize (
    args)) (i) (addNodeOnListOfTuple ("--start", getStartNbr (args) -  1) (
      args)) (createNextLine (getRuleNbr args) (actualLine))
  | charNotPrinted > 0 = putStrLn (init(removeCharOnString (charNotPrinted) (
    actualLine))) >> printLine (length (actualLine) - getWindowSize (args)) (
      i + 1) args (createNextLine (getRuleNbr args) (actualLine))
  | otherwise = putStrLn (init(actualLine)) >> printLine (length (
    actualLine) - getWindowSize (args)) (i + 1) args nextLine
      where nextLine = createNextLine (getRuleNbr args) (actualLine)

mainAlgorithm :: [(String, Int)] -> String -> IO ()
mainAlgorithm args firstLine = printLine (length (firstLine) - getWindowSize (
  args) - 1) (0) (args) (firstLine)

wolfram :: [(String, Int)] -> IO ()
wolfram args = mainAlgorithm (args) (createFirstLine (0) (getMoveNbr (args))
              (getWindowSize (args)) "")

main :: IO ()
main = do
  args <- getArgs
  if checkIfGood (args) && checkMandatoryRule (args) then
      (wolfram (setArgsOnTuple (createBaseListArgs) (args)))
  else
    exitWith(ExitFailure 84)
