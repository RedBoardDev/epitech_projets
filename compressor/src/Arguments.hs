{-
-- EPITECH PROJECT, 2022
-- oui
-- File description:
-- oui
-}

module Arguments (setNArg, setLArg, setFArg) where
import Data.Maybe (mapMaybe)

splitOnTuple :: String -> (String, String)
splitOnTuple (')':xs) = ([')'], xs)
splitOnTuple (x:xs) = let (ys, zs) = splitOnTuple xs in (x:ys, zs)
splitOnTuple _ = ("", "")

readTuple :: Read a => String -> Maybe a
readTuple arg
    | [(result, "")] <- reads arg = Just result
    | otherwise = Nothing

parseLines :: String -> Maybe ((Int, Int), (Int, Int, Int))
parseLines line
    | (Just t1, Just t2) <- (readTuple p1, readTuple p2) = Just (t1, t2)
    | otherwise = Nothing
    where (p1, p2) = splitOnTuple line

getDataIntoFile :: FilePath -> IO [((Int, Int), (Int, Int, Int))]
getDataIntoFile filepath = do
    content <- readFile filepath
    return (mapMaybe parseLines (lines content))

setFArg :: [String] -> IO [((Int, Int), (Int, Int, Int))]
setFArg ("-f":s:xs) = getDataIntoFile s
setFArg (_:xs) = setFArg xs
setFArg [] = return [((0, 0), (0, 0, 0))]

setNArg :: [String] -> Int
setNArg ("-n":s:xs) = read s
setNArg (_:xs) = setNArg xs
setNArg [] = 0

setLArg :: [String] -> Float
setLArg ("-l":s:xs) = read s
setLArg (_:xs) = setLArg xs
setLArg [] = 0.0
