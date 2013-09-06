package careercup;

import java.util.Stack;

/**
 * 
 * @ClassName: HanoiTower
 * @Description: implement tower of hanoi by stacks
 * @author zhouyu
 * @date 2013-8-9 ÉÏÎç8:46:10
 * @version V0.1 
 *
 */
public class HanoiTower {
	
	private Stack<Integer> tower;
	
	private int index;
	
	public HanoiTower(int n){
		tower = new Stack<Integer>();
		index = n;
	}
	
	public int getIndex(){
		return index;
	}
	
	public void add(int n){
		if(tower.size() > 0 && tower.peek() <= n)
			System.out.println("Error placing disk " + n);
		else
			tower.push(n);
	}
	
	public void moveTopTo(HanoiTower h){
		int top = tower.pop();
		h.add(top);
		System.out.println("Move disk " + top + " from " + index + " to " + h.getIndex());
	}
	
	public void moveDisks(int n, HanoiTower dest, HanoiTower tmp){
		if(n > 0){
			moveDisks(n - 1, tmp, dest);
			moveTopTo(dest);
			tmp.moveDisks(n - 1, dest, this);
		}
	}
	
	public static void main(String[] args){
		int n = 5;
		HanoiTower[] towers = new HanoiTower[3];
		for(int i = 0;i < 3;i++)
			towers[i] = new HanoiTower(i);
		for(int i = n;i >= 1;i--)
			towers[0].add(i);
		towers[0].moveDisks(n, towers[2], towers[1]);
	}
}
