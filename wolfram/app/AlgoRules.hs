{-
-- EPITECH PROJECT, 2022
-- B-FUN-400-MLH-4-1-wolfram-thomas.ott
-- File description:
-- AlgoRules.hs
-}

module AlgoRules (algoRule30, algoRule90, algoRule110) where

algoRule30 :: String -> String
algoRule30 ('*':'*':'*':xs) =  " " ++ algoRule30 ('*':'*':xs)
algoRule30 ('*':'*':' ':xs) =  " " ++ algoRule30 ('*':' ':xs)
algoRule30 ('*':' ':'*':xs) =  " " ++ algoRule30 (' ':'*':xs)
algoRule30 ('*':' ':' ':xs) =  "*" ++ algoRule30 (' ':' ':xs)
algoRule30 (' ':'*':'*':xs) =  "*" ++ algoRule30 ('*':'*':xs)
algoRule30 (' ':'*':' ':xs) =  "*" ++ algoRule30 ('*':' ':xs)
algoRule30 (' ':' ':'*':xs) =  "*" ++ algoRule30 (' ':'*':xs)
algoRule30 (' ':' ':' ':xs) =  " " ++ algoRule30 (' ':' ':xs)
algoRule30 _ = ""

algoRule90 :: String -> String
algoRule90 ('*':'*':'*':xs) =  " " ++ algoRule90 ('*':'*':xs)
algoRule90 ('*':'*':' ':xs) =  "*" ++ algoRule90 ('*':' ':xs)
algoRule90 ('*':' ':'*':xs) =  " " ++ algoRule90 (' ':'*':xs)
algoRule90 ('*':' ':' ':xs) =  "*" ++ algoRule90 (' ':' ':xs)
algoRule90 (' ':'*':'*':xs) =  "*" ++ algoRule90 ('*':'*':xs)
algoRule90 (' ':'*':' ':xs) =  " " ++ algoRule90 ('*':' ':xs)
algoRule90 (' ':' ':'*':xs) =  "*" ++ algoRule90 (' ':'*':xs)
algoRule90 (' ':' ':' ':xs) =  " " ++ algoRule90 (' ':' ':xs)
algoRule90 _ = ""

algoRule110 :: String -> String
algoRule110 ('*':'*':'*':xs) =  " " ++ algoRule110 ('*':'*':xs)
algoRule110 ('*':'*':' ':xs) =  "*" ++ algoRule110 ('*':' ':xs)
algoRule110 ('*':' ':'*':xs) =  "*" ++ algoRule110 (' ':'*':xs)
algoRule110 ('*':' ':' ':xs) =  " " ++ algoRule110 (' ':' ':xs)
algoRule110 (' ':'*':'*':xs) =  "*" ++ algoRule110 ('*':'*':xs)
algoRule110 (' ':'*':' ':xs) =  "*" ++ algoRule110 ('*':' ':xs)
algoRule110 (' ':' ':'*':xs) =  "*" ++ algoRule110 (' ':'*':xs)
algoRule110 (' ':' ':' ':xs) =  " " ++ algoRule110 (' ':' ':xs)
algoRule110 _ = ""
