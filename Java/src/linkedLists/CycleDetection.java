package linkedLists;

public class CycleDetection {

	// Floyd's algorithm
	public boolean isCyclic(LinkedList list) {
		LinkedListNode slowPtr = list.getHead(), fastPtr = list.getHead();
		while(fastPtr != null && slowPtr != null){
			fastPtr = fastPtr.getNext();
			if(fastPtr == slowPtr) return true;
			if(fastPtr == null) return false;
			fastPtr = fastPtr.getNext();
			if(fastPtr == slowPtr) return true;
			slowPtr = slowPtr.getNext();
		}
		return false;
	}
	
	// finds the starting node of the cycle
	public LinkedListNode findLoopStart(LinkedList list){
		LinkedListNode slowPtr = list.getHead(), fastPtr = list.getHead();
		boolean cyclic = false;
		while(slowPtr != null && fastPtr != null){
			fastPtr = fastPtr.getNext();
			if(fastPtr == slowPtr) {
				cyclic = true;
				break;
			}
			if(fastPtr == null){
				cyclic = false;
				break;
			}
			fastPtr = fastPtr.getNext();
			if(fastPtr == slowPtr){
				cyclic = true;
				break;
			}
			slowPtr = slowPtr.getNext();
		}
		
		// if cycle exists
		if(cyclic){
			slowPtr = list.getHead();
			while(slowPtr != fastPtr){
				slowPtr = slowPtr.getNext();
				fastPtr = fastPtr.getNext();
			}
			return slowPtr;
		}
		return null;
	}
	
	// find length of the loop
	public int findLoopLength(LinkedList list){
		boolean cyclic = false;
		int length = 0;
		LinkedListNode slowPtr = list.getHead(), fastPtr = list.getHead();
		while(fastPtr != null && slowPtr != null){
			fastPtr = fastPtr.getNext();
			if(fastPtr == slowPtr){
				cyclic = true;
				break;
			}
			if(fastPtr == null){
				break;
			}
			fastPtr = fastPtr.getNext();
			if(fastPtr == slowPtr){
				cyclic = true;
				break;
			}
			slowPtr = slowPtr.getNext();
		}
		if(cyclic){
			while(slowPtr != fastPtr){
				slowPtr = slowPtr.getNext();
				length++;
			}
		}
		return length;
	}
}
