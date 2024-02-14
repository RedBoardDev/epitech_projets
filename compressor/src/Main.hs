{-
-- EPITECH PROJECT, 2022
-- oui
-- File description:
-- oui
-}

module Main (main) where
import ErrorHandlings (checkIfArgsGood)
import Arguments (setNArg, setLArg, setFArg)
import Algo (algo, initClusters)
import Print (printOutput)

import System.Environment
import System.Exit

checkArgs:: [String] -> IO()
checkArgs args
    | checkIfArgsGood (args) == False = exitWith(ExitFailure 84)
    | otherwise = return()

main :: IO ()
main = do
    args <- getArgs
    checkArgs args

    clusters <- initClusters (setNArg (args))
    feur <- setFArg (args)
    let out = algo clusters (setLArg (args)) (feur)
    printOutput (out)
