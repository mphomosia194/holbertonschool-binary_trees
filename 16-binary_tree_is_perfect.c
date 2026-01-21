#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * is_perfect - checks if a binary tree is perfect recursively
 * @tree: pointer to the root node
 * @depth: expected depth of leaves
 * @level: current level
 *
 * Return: 1 if perfect, otherwise 0
 */
static int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = height(tree);
	return (is_perfect(tree, depth, 0));
}
