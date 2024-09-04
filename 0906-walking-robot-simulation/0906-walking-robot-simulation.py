class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs_set = set(map(tuple, obstacles))
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        

        curr_x, curr_y = 0, 0
        dir_idx = 0        
        max_dist = 0
        
        for command in commands:
            if command == -2:
                dir_idx = (dir_idx - 1) % 4
            elif command == -1:
                dir_idx = (dir_idx + 1) % 4
            else:
                for _ in range(command):
                    next_x = curr_x + dirs[dir_idx][0]
                    next_y = curr_y + dirs[dir_idx][1]
                    if (next_x, next_y) in obs_set:
                        break
                    
                    curr_x, curr_y = next_x, next_y
                    max_dist = max(max_dist, curr_x * curr_x + curr_y * curr_y)
        
        return max_dist