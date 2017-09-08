// Doubly Linked List
public class DNode {

	DNode next = null;
	DNode prev = null;
	int data;
	
	public DNode(int d)
	{
		this.data = d;
	}
	
	void appendToTail(int d)
	{
		DNode end = new DNode(d);
		DNode n = this;
		DNode tmp = null;
		while (n.next != null)
		{
			tmp = n;
			n = n.next;
			n.prev = tmp;
		}
		n.next = end;
		end.prev = n;
	}
}
