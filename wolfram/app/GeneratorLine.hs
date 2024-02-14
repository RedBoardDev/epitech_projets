{-
-- EPITECH PROJECT, 2022
-- B-FUN-400-MLH-4-1-wolfram-thomas.ott
-- File description:
-- GeneratorLine.hs
-}

module GeneratorLine (createFirstLine, createNextLine) where
import AlgoRules (algoRule30, algoRule90, algoRule110)

createFirstLine :: Int -> Int -> Int -> String -> String
createFirstLine i move lineMaxSize line
  | i >= lineMaxSize = line ++ " "
  | i == position_etoile = createFirstLine (i + 1
        ) move lineMaxSize ("*" ++ line)
  | otherwise = createFirstLine (i + 1) move lineMaxSize (" " ++ line)
  where
    position_etoile = ((lineMaxSize `div` 2) - move) - 1

createNextLine :: Int -> String -> String
createNextLine _ [] = []
createNextLine ruleNbr actualLine
  | 30 <- ruleNbr = algoRule30 ("  " ++ actualLine ++ "  ")
  | 90 <- ruleNbr = algoRule90 ("  " ++ actualLine ++ "  ")
  | 110 <- ruleNbr = algoRule110 ("  " ++ actualLine ++ "  ")
  | otherwise = ""
