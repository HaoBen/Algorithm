package _07;

public class Test {
	public static void main(String[] args) {
		Solution solution= new Solution();
		TreeNode root = new TreeNode(1);
		root.left = new TreeNode(2);
		root.right = new TreeNode(3);
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(5);
		root.right.right = new TreeNode(6);
		root.right.right.right = new TreeNode(7);
		
		String data = solution.serialize(root);
		System.out.println(data);
		
		TreeNode deroot = solution.deserialize(data);
		post(deroot);
	}
	
	public static void post(TreeNode root) {
		if(root==null) return;
		post(root.left);
		post(root.right);
		System.out.println(root.val);
	}

}
