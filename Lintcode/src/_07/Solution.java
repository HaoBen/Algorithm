package _07;

import java.util.ArrayList;
import java.util.List;

public class Solution {
	int index = -1;
	public String serialize(TreeNode root) {
		StringBuilder builder = new StringBuilder();
		pre(root,builder);
		return builder.toString();
	}
	private void pre(TreeNode root,StringBuilder builder) {
		if(root == null) {
			builder.append("#,");
		} else {
			builder.append(root.val+",");
			pre(root.left,builder);
			pre(root.right,builder);
		}
	}
	
	public TreeNode deserialize(String data) {
		index++;
		String[] seqStr = data.split(",");
		TreeNode current;
		if(seqStr[index].equals("#")) 
			current=null;
		else {
			current = new TreeNode(Integer.parseInt(seqStr[index]));
			current.left = deserialize(data);
			current.right = deserialize(data);
		}
		return current;
	}
}
