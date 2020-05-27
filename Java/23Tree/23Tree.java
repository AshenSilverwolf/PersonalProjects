class TwoThreeNode {
	int data1, data2, data3, size;
	TwoThreeNode left, right, center;

	public TwoThreeNode() {
		this.data1 = this.data2 = this.data3 = this.size = 0;
		this.left = this.right = this.center = null;
	}

	public TwoThreeNode(int key) {
		this.data1 = key;
		this.data2 = this.data3 = 0;
		this.size = 1;
		this.left = this.right = this.center = null;
	}
}

class TwoThreeTree {
	TwoThreeNode root;

	public TwoThreeTree() {
		this.root = null;
	}

	void insert(int key) {

		if (this.root == null) {
			this.root = prot1(key);
			return;
		}
		if (this.root.data1 == key || this.root.data2 == key)
			return;

		insertRecursive(root, key);
	}

	TwoThreeNode insertRecursive(TwoThreeNode node, int key) {

		if (node == null)
			return prot1(key);
		if (node.data1 == key || node.data2 == key)
			return node;

		
	}

	// Inserting into null node
	TwoThreeNode prot1(int key) {

		return new TwoThreeNode(key);
	}

	// Inserting into node size = 1
	TwoThreeNode prot2(TwoThreeNode child, int key) {

		if (key < child.data1) {
			child.data2 = child.data1;
			child.data1 = key;
		} else {
			child.data2 = key;
		}
	}

	// Inserting into full node
	TwoThreeNode prot3(TwoThreeNode child, TwoThreeNode parent, int key) {


	}

	void delete(int key) {


	}

	void search(int key) {

		boolean found = searchRecursive(this.root, key);

		if (found)
			System.out.println("Data " + key + " Found.");
		else
			System.out.println("Data " + key + " Not Found.");
	}

	boolean searchRecursive(TwoThreeNode node, int key) {

		if (node == null)
			return false;
		else if (node.data1 == key || node.data2 == key)
			return true;
		
		if (key < node.data1) {
			return searchRecursive(node.left, key);
		} else if (node.size == 1) {
			return searchRecursive(node.center, key);
		} else {
			return searchRecursive(node.right, key);
		}
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