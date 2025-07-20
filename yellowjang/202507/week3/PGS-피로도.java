class Solution {
    int maxCount = 0;

    public int solution(int k, int[][] dungeons) {
        boolean[] visited = new boolean[dungeons.length];
        dfs(k, dungeons, visited, 0);
        return maxCount;
    }

    public void dfs(int energy, int[][] dungeons, boolean[] visited, int count) {
        maxCount = Math.max(maxCount, count);

        for (int i = 0; i < dungeons.length; i++) {
            int need = dungeons[i][0];
            int consume = dungeons[i][1];

            if (!visited[i] && energy >= need) {
                visited[i] = true;
                dfs(energy - consume, dungeons, visited, count + 1);
                visited[i] = false; // 백트래킹
            }
        }
    }
}
