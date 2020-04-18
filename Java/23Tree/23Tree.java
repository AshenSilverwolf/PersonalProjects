class TwoThreeNode {
	int data1, data2;
	TwoThreeNode left, right, center;

	public TwoThreeNode() {
		this.data1 = this.data2 = 0;
		this.left = this.right = this.center = null;
	}
}

class TwoThreeTree {
	TwoThreeNode root;

	public TwoThreeTree() {
		this.root = null;
	}

	void insert(int key) {

		TwoThreeNode nearest = searchRecursive(root, key);
		// PICK UP HERE
	}

	void split() {


	}

	void delete(int key) {


	}

	void search(int key) {

		TwoThreeNode walker = root;
		TwoThreeNode nearest = searchRecursive(walker, key);

		if (nearest.data1 == key || nearest.data2 == key)
			System.out.println("Data " + key + " Found.");
		else
			System.out.println("Data " + key + " Not Found.");
	}

	TwoThreeNode searchRecursive(TwoThreeNode node, int key) {

		if (node == null) return null;
		if (node.data1 == key || node.data2 == key) return node;
		
		if (key < node.data1)
			return searchRecursive(node.left, key);
		else if (node.data2 != 0 && key > node.data2)
			return searchRecursive(node.right, key);
		else
			return searchRecursive(node.center, key);
	}

	void printInorder() {

		TwoThreeNode walker = root;

		if (walker == null) {
			System.out.println("This tree is empty.");
			return;
		}

		printRecursive(walker);
	}

	void printRecursive(TwoThreeNode node) {
		
		if (node == null)
			return;


		printRecursive(node.left);
		System.out.println(node.data1);
		printRecursive(node.center);
		if (node.data2 > 0) {
			System.out.println(node.data2);
			printRecursive(node.right);
		}
	}
}