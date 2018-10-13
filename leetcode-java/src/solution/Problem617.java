package solution;

import java.util.Stack;

/**
 * 
 * @author Akarin
 *
 */
public class Problem617 {

	/**
	 * Object required by the assigment
	 * 
	 * @author Akarin
	 *
	 */
	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

	/**
	 * This solution is accepted by LeetCode. The code is O(n) which I think as good
	 * as it gets?
	 * 
	 * @param firstNode
	 *            the first TreeNode.
	 * @param secondNode
	 *            the second TreeNode.
	 * @return a TreeNode where the nodes are the sum of the corresponding nodes in
	 *         t1 and t2.
	 */
	public TreeNode solution(TreeNode firstNode, TreeNode secondNode) {
		if (firstNode != null && secondNode != null) {
			/**
			 * If the first and second nodes are not null, then we perform the sum, the left
			 * and right leaf of these nodes are the sum too (That is we call this function
			 * recursively again).
			 */
			firstNode.val += secondNode.val;
			firstNode.left = solution(firstNode.left, secondNode.left);
			firstNode.right = solution(firstNode.right, secondNode.right);

			return firstNode;
		} else if (firstNode != null && secondNode == null) {
			/**
			 * If the second node is null, just return the first node.
			 */
			return firstNode;

		} else if (firstNode == null && secondNode != null) {
			/**
			 * If the first node is null, then just return the second node.
			 */
			return secondNode;
		}

		// Means that both the given nodes null, then we just return null
		return firstNode;
	}

	/**
	 * Solution from https://leetcode.com/problems/merge-two-binary-trees/solution/
	 */
	public class LeetCodeSolution {

		/**
		 * We can traverse both the given trees in a preorder fashion. At every step, we
		 * check if the current node exists(isn't null) for both the trees. If so, we
		 * add the values in the current nodes of both the trees and update the value in
		 * the current node of the first tree to reflect this sum obtained. At every
		 * step, we also call the original function mergeTrees() with the left children
		 * and then with the right children of the current nodes of the two trees. If at
		 * any step, one of these children happens to be null, we return the child of
		 * the other tree(representing the corresponding child subtree) to be added as a
		 * child subtree to the calling parent node in the first tree. At the end, the
		 * first tree will represent the required resultant merged binary tree.
		 * 
		 * @param firstNode
		 *            The first TreeNode
		 * @param secondNode
		 *            The second TreeNode
		 * @return
		 */
		public TreeNode solution1(TreeNode firstNode, TreeNode secondNode) {
			if (firstNode == null)
				return secondNode;
			if (secondNode == null)
				return firstNode;
			firstNode.val += secondNode.val;
			firstNode.left = solution1(firstNode.left, secondNode.left);
			firstNode.right = solution1(firstNode.right, secondNode.right);
			return firstNode;
		}

		/**
		 * In the current approach, we again traverse the two trees, but this time we
		 * make use of a stackstack to do so instead of making use of recursion. Each
		 * entry in the stackstack strores data in the form
		 * [nodetree1,nodetree2][node_{tree1}, node_{tree2}]. Here,
		 * nodetree1node_{tree1} and nodetree2node_{tree2} are the nodes of the first
		 * tree and the second tree respectively.
		 * 
		 * We start off by pushing the root nodes of both the trees onto the stackstack.
		 * Then, at every step, we remove a node pair from the top of the stack. For
		 * every node pair removed, we add the values corresponding to the two nodes and
		 * update the value of the corresponding node in the first tree. Then, if the
		 * left child of the first tree exists, we push the left child(pair) of both the
		 * trees onto the stack. If the left child of the first tree doesn't exist, we
		 * append the left child(subtree) of the second tree to the current node of the
		 * first tree. We do the same for the right child pair as well.
		 * 
		 * If, at any step, both the current nodes are null, we continue with popping
		 * the next nodes from the stackstack.
		 * 
		 * @param firstNode
		 * @param secondNode
		 * @return
		 */
		public TreeNode solution2(TreeNode firstNode, TreeNode secondNode) {
			if (firstNode == null)
				return secondNode;
			Stack<TreeNode[]> stack = new Stack<>();
			stack.push(new TreeNode[] { firstNode, secondNode });
			while (!stack.isEmpty()) {
				TreeNode[] t = stack.pop();
				if (t[0] == null || t[1] == null) {
					continue;
				}
				t[0].val += t[1].val;
				if (t[0].left == null) {
					t[0].left = t[1].left;
				} else {
					stack.push(new TreeNode[] { t[0].left, t[1].left });
				}
				if (t[0].right == null) {
					t[0].right = t[1].right;
				} else {
					stack.push(new TreeNode[] { t[0].right, t[1].right });
				}
			}
			return firstNode;
		}
	}
}
