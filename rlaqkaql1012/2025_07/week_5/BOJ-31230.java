package BOJ31230;

import java.util.*;
import java.io.*;

/*
 * BOJ 31230
 * 스터디를 한다.
 * N번까지 번호가 부여된 N개의 도시와, M개의 양방향 도로가 있는 나라에서 산다.
 * 도로마다 통행하는 시간이 양의 정수로 존재하고
 * 모든 도시는 연결되어있다. 도시간에는 도로가 최대 1개 있다.
 * A-B 도시의 최단 경로위의 도시로 약속장소를 정한다.
 * A,B도 될 수 있다.
 * 가능한 도시의 수와, 도시의 번호를 오름차순으로 출력하라.
 * 도시수 N, 도로수 M, fromA, ToB N<=20만, M<=30만
 * 
 * 양방향 가중치 그래프 최단 경로 찾기
 * Node to Node 최단경로 : 다익스트라
 * A로부터 다익스트라 = distA[]
 * B로부터 다익스트라 = distB[]
 * 최단 거리 = distA[B]
 * 모든 도시 c에 대해, distA[c] + distB[c] == distA[B]?
 * c는 가능
 * 
 * 
 */
public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static int N,M,A,B;
	static List<List<Road>> graph;
	static PriorityQueue<Road> queue;
	static Set<Integer> route;
	static class Road implements Comparable<Road>{
		
		int to;
		long weight;
		
		Road(int to, long weight){
			this.to = to;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Road o) {
			return Long.compare(this.weight, o.weight);
		}
	}
	
	public static void main(String[] args) throws Exception{
		br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList<>();
		for(int i=0; i<=N;i++) {
			graph.add(new ArrayList<>());
		}
		
		
		for(int RoadIdx=0; RoadIdx<M; RoadIdx++) {
			st = new StringTokenizer(br.readLine());
			int from =Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			long weight = Long.parseLong(st.nextToken());
			graph.get(from).add(new Road(to,weight));
			graph.get(to).add(new Road(from,weight));
		}
		long[] distA = dijkstra(A);
		long[] distB = dijkstra(B);
		long shortest = distA[B];
		route = new HashSet<>();
		for(int city = 1; city<=N;city++) {
			if(distA[city]+distB[city]== shortest) {
				route.add(city);
			}
		}
		PrintPath();

	}
	
	static long[] dijkstra(int start) {
		queue = new PriorityQueue<>();
		long[] dist = new long[N+1];
		Arrays.fill(dist, Long.MAX_VALUE);
		dist[start] =0;
		queue.offer(new Road(start,0));
		
		while(!queue.isEmpty()) {
			Road now = queue.poll();
			if( now.weight > dist[now.to]) continue; //갱신안되면 안감
			for(Road nxt : graph.get(now.to)) { //연결된 모든 길에 대해 점검
				long cost = dist[now.to]+ nxt.weight;
				if(cost < dist[nxt.to]) {
					dist[nxt.to] = cost;
					queue.offer(new Road(nxt.to,cost));
				}
			}
		}
		return dist;
		
	}
	
	static void PrintPath() {
		List<Integer> sorted = new ArrayList<>(route);
		Collections.sort(sorted);
		System.out.println(sorted.size());
	    for (int i = 0; i < sorted.size(); i++) {
	        System.out.print(sorted.get(i));
	        if (i < sorted.size() - 1) System.out.print(" ");
	    }
	    System.out.println(); 
	}
	
}
