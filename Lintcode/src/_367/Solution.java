package _367;

import java.util.Stack;

public class Solution {
	public ExpressionTreeNode build(String[] expression){
		Stack<String> operators = new Stack<String>();		//运算符栈
		Stack<ExpressionTreeNode> nodes = new Stack<ExpressionTreeNode>();	//节点栈
		for(int i = 0;i < expression.length;++i){
			if(isNumberic(expression[i])) {	//处理数值
				ExpressionTreeNode tmp = new ExpressionTreeNode(expression[i]);
				nodes.push(tmp);
			} else {	//处理运算符
				if(operators.isEmpty())	//运算符栈为空,直接入栈
					operators.push(expression[i]);
				else if(expression[i].equals(")")) {	//运算符为),进行一系列出栈操作,直到(为止
					String operator;
					operator = operators.pop();
					while(!operator.equals("(")) {
						ExpressionTreeNode node = new ExpressionTreeNode(operator);
						node.right = nodes.pop();
						node.left = nodes.pop();
						nodes.push(node);
						operator = operators.pop();
					}
				}
				else if(getPriority(expression[i]) > getPriority(operators.lastElement()) || operators.lastElement().equals("(")) {	//当前运算符优先级大于栈顶元素,直接入栈
					operators.push(expression[i]);
				} else {	//当前运算符优先级小于等于栈顶元素,进行一系列出栈操作,直到当前运算符优先级大于栈顶元素或者栈为空为止
					while(!operators.isEmpty() && !operators.lastElement().matches("[()]")) {
						if(getPriority(expression[i])>getPriority(operators.lastElement())) {
							break;
						}
						String operator = operators.pop();
						ExpressionTreeNode node = new ExpressionTreeNode(operator);
						node.right = nodes.pop();
						node.left = nodes.pop();
						nodes.push(node);
					}
					operators.push(expression[i]);
				}				
			}
		}	//end for
		while(!operators.isEmpty()) {
			String operator = operators.pop();
			ExpressionTreeNode node = new ExpressionTreeNode(operator);
			node.right = nodes.pop();
			node.left = nodes.pop();
			nodes.push(node);
		}	
		return nodes.isEmpty()?null:nodes.pop();
	}
	
	//判断运算符的优先级
	//*,/  为2
	//+,- 为1
	int getPriority(String operator) {
		if(operator == null)
			return Integer.MIN_VALUE;
		if(operator.equals("+") || operator.equals("-"))
			return 1;
		else if(operator.equals("*") || operator.equals("/"))
			return 2;
		else if(operator.equals("("))
				return 3;
		else {
			return Integer.MIN_VALUE;
		}
	}
	//判断字符串是否为数字
	public boolean isNumberic(String str) {
		return str.matches("[0-9]+");
	}
}
