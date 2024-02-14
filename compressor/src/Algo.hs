{-
-- EPITECH PROJECT, 2022
-- oui
-- File description:
-- oui
-}

module Algo (algo, initClusters) where
import System.Random

initClusters:: Int -> IO [(Int, Int, Int)]
initClusters 0 = return []
initClusters nb = do
        r <- randomRIO (1, 255)
        g <- randomRIO (1, 255)
        b <- randomRIO (1, 255)
        n <- initClusters (nb - 1)
        return ((r, g, b) : n)

sQ::Int -> Int
sQ nb = nb * nb

pointDistance::(Int, Int, Int) -> (Int, Int, Int) -> Float
pointDistance (a1,a2,a3) (b1,b2,b3) = sqrt ( fromIntegral((sQ (a1 - b1))
        + (sQ(a2 - b2)) + (sQ(a3 - b3))) )

findClosestClock:: Int ->  Float -> Int -> [(Int, Int, Int)] ->
    ((Int, Int), (Int, Int, Int)) -> Int
findClosestClock i l index clusts (point,rgb)
    | i == -1 = index
    | dist < l = findClosestClock (i - 1) dist i clusts (point, rgb)
    | otherwise = findClosestClock (i - 1) l index clusts (point, rgb)
    where dist = (pointDistance (clusts !! i) rgb)

findClosest:: [(Int, Int, Int)] -> ((Int, Int), (Int, Int, Int)) -> Int
findClosest clusts point = findClosestClock
        ((length clusts) - 1) 10000.0 (-1) clusts point

doAssignClust::((Int, Int), (Int, Int, Int)) -> [((Int, Int), (Int, Int, Int))] -> [((Int, Int), (Int, Int, Int))]
doAssignClust point points = points ++ [point]

assignClustSelect:: ((Int, Int), (Int, Int, Int))
        -> ((Int, Int, Int), [((Int, Int), (Int, Int, Int))])
        -> ((Int, Int, Int), [((Int, Int), (Int, Int, Int))])
assignClustSelect point (coords, points) =
        (coords ,(doAssignClust point points))

assignClust :: Int -> ((Int, Int), (Int, Int, Int)) -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
assignClust 0 point (x:xs) = (assignClustSelect point x) : xs
assignClust pos point (x:xs) = x : assignClust (pos - 1) point xs
assignClust _ _ _ = []

doCluster:: [(Int, Int, Int)] -> ((Int, Int), (Int, Int, Int)) -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
doCluster clusts point points =
        assignClust (findClosest clusts point) point points

clusterize:: [(Int, Int, Int)] ->  [((Int, Int), (Int, Int, Int))] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
clusterize clusts (x:xs) points
    | length xs == 0 = doCluster clusts x points
    | otherwise = clusterize clusts xs (doCluster clusts x points)
clusterize _ _ _ = []

genEmptyClust::[(Int, Int, Int)] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
genEmptyClust (x:xs)
    | length xs == 0 = [(x, [])]
    | otherwise = (x, []):(genEmptyClust xs)
genEmptyClust _ = []

checkIter:: Float -> [(Int, Int, Int)] -> [(Int, Int, Int)] -> Bool
checkIter limit (x:xs) (y:ys)
    | length (y:ys) == 0 = True
    | (pointDistance x y) > limit = True
    | length xs == 0 = False
    | otherwise = checkIter limit xs ys
checkIter _ _ [] = True
checkIter _ [] _ = True

calcClustMedClock:: Int -> [((Int, Int), (Int, Int, Int))] -> (Int, Int, Int) -> (Int, Int, Int) -> (Int, Int, Int)
calcClustMedClock _ [] _ old = old
calcClustMedClock x ((_, (r,g,b)):xs) (oa, ob, oc) old
    | length xs == 0 =
                (((oa + r) `div` x), ((ob + g) `div` x), ((oc + b) `div` x))
    | otherwise = calcClustMedClock x xs (oa + r, ob + g, oc + b)  old

calcClustMed::[((Int, Int), (Int, Int, Int))] -> (Int, Int, Int) -> (Int, Int, Int)
calcClustMed points old = calcClustMedClock (length points) points (0,0,0) old

getNewClusts:: [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> [(Int, Int, Int)]
getNewClusts ((old, points):xs)
    | length xs == 0 = [calcClustMed points old]
    | otherwise = (calcClustMed points old) : (getNewClusts xs)
getNewClusts _  = []



checkEmptyClust::[((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> Bool
checkEmptyClust ((_, b):xs)
    | length b == 0 = True
    | length xs == 0 = False
    | otherwise = checkEmptyClust xs
checkEmptyClust _ = True

getTheThing::((Int, Int), (Int, Int, Int)) -> (Int, Int, Int)
getTheThing (_, b) = b

getAPoint:: [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> Int -> (Int, Int, Int)
getAPoint (( _ , tab):_) i = getTheThing (tab !! i)
getAPoint _ _ = (0,0,0)


fillTheClust:: [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> ((Int, Int, Int), [((Int, Int), (Int, Int, Int))]) -> ((Int, Int, Int), [((Int, Int), (Int, Int, Int))])
fillTheClust ((p,b):xs) ((p1,p2,p3), o)
    | length b > 1 = ( (getAPoint ((p,b):xs) (p1 `mod` (length b)) ), o)
    | otherwise = fillTheClust xs ((p1,p2,p3), o)
fillTheClust _ a = a


fillEmptyClustClock::[((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
fillEmptyClustClock c ((a,b):xs)
    | length xs == 0 && length b == 0 = [(fillTheClust c (a,b))]
    | length xs == 0 = [(a, b)]
    | length b == 0 = (fillTheClust c (a,b)): (fillEmptyClustClock c xs)
    | otherwise = (a,b) : (fillEmptyClustClock c xs)
fillEmptyClustClock _ _ = []

fillEmptyClust::[((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
fillEmptyClust obj = fillEmptyClustClock obj obj


clusterIterations:: Float -> [(Int, Int, Int)] -> [(Int, Int, Int)]
        -> [((Int, Int), (Int, Int, Int))]
        -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
        -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
clusterIterations limit clusts oldClusts points doneClusters
    | checkIter limit clusts oldClusts == True ||
            checkEmptyClust doneClusters == True =
                clusterIterations limit newClust clusts points
                (clusterize newClust points (genEmptyClust newClust))
    | otherwise =  doneClusters
    where newClust = (getNewClusts (fillEmptyClust doneClusters))

algo::[(Int, Int, Int)] -> Float -> [((Int, Int), (Int, Int, Int))] ->  [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
algo clusters b file =
            clusterIterations b clusters [] file
            (clusterize clusters file (genEmptyClust clusters))
