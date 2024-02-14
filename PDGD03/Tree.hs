{-
-- EPITECH PROJECT, 2022
-- B-PDG-300-MLH-3-1-PDGD03-thomas.ott
-- File description:
-- Tree.hs
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving(Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node t1 v t2)
    | v == x = Node t1 v t2
    | v < x = Node t1 v (addInTree x t2)
    | v > x = Node (addInTree x t1) v t2

instance Functor Tree where
    fmap _ Empty = Empty
    fmap fct (Node t1 v t2) = Node (fmap fct t1) (fct v) (fmap fct t2)

instance Foldable Tree where
    foldr f z n = foldr f z (treeToList n)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree(x)(listToTree(xs))

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node t1 v t2) = treeToList t1 ++ [v] ++ treeToList t2

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort a = treeToList(listToTree(a))
