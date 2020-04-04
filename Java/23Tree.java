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


	}

	void split() {


	}

	void delete(int key) {


	}

	void search(int key) {


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
		if (data2 > 0)
			System.out.println(node.data2);
		printRecursive(node.right);
	}
}