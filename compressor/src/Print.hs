{-
-- EPITECH PROJECT, 2022
-- oui
-- File description:
-- oui
-}

module Print (printOutput) where

setStringCoord :: ((Int, Int), (Int, Int, Int)) -> IO ()
setStringCoord ((x, s), (r, m, n)) =
    let ret = "(" ++ (show x) ++ "," ++ (show s) ++ ")"
            ++ " (" ++ (show r) ++ "," ++ (show m) ++ "," ++ (show n) ++ ")"
    in putStrLn ret

printClusterCoord :: [((Int, Int), (Int, Int, Int))] -> IO ()
printClusterCoord [] = return ()
printClusterCoord ((x, y) : xs) =
    setStringCoord (x, y) >> printClusterCoord xs

printClusterColor :: (Int, Int, Int) -> IO ()
printClusterColor (x, s, r) =
    let ret = "--\n(" ++ (show x) ++ ","
            ++ (show s) ++ "," ++ (show r) ++ ")\n-"
    in putStrLn ret

printSingleCluster :: ((Int, Int, Int), [((Int, Int), (Int, Int, Int))]) -> IO ()
printSingleCluster (x, s) =
    printClusterColor x >> printClusterCoord s >> return ()

printOutput :: [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> IO ()
printOutput [] = return ()
printOutput (x:xs) =
    printSingleCluster x >> printOutput xs
