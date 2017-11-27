package _378;

public class Solution {
	public DoublyListNode bstToDoublyList(TreeNode root) {
		DoublyListNode head = new DoublyListNode(0);
		inorder(root,head);
		return head;
	}
	
	private DoublyListNode inorder(TreeNode current,DoublyListNode parent) {
		if(current == null) return parent;
		
		DoublyListNode tmp = inorder(current.left,parent);	//左
		
		tmp.next = new DoublyListNode(current.val);
		tmp.next.prev = tmp;		//中
		
		tmp = tmp.next;			//右
		tmp = inorder(current.right,tmp);
		
		return tmp;
		
	}
}
