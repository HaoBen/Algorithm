package _367;

public class ExpressionTreeNode {
	public String symbol;
	ExpressionTreeNode left,right;
	public ExpressionTreeNode(String symbol) {
		this.symbol = symbol;
		this.left = this.right = null;
	}
}
