class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Using Topological Sort - Kahn’s algorithm
        // There exists a topological ordering <-> graphs doesn't have cycles

        vector<vector<int>> GraphAdj(numCourses, vector<int>());
        vector<int> Indegree(numCourses);
        queue<int> q;
        int length=0;  // topological ordering length

        for(auto course: prerequisites){
            // course[1]->course[0]
            GraphAdj[course[1]].push_back(course[0]);
            Indegree[course[0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(!Indegree[i])
                q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            length++;  // push back to topological ordering

            // remove all out-degree from the node
            for(auto _nextCourse: GraphAdj[node]){
                Indegree[_nextCourse]--;
                if(Indegree[_nextCourse]==0){
                    q.push(_nextCourse);
                }
            }
        }

        return length==numCourses;
    }
};