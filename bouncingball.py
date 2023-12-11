def find_collision_steps(m, n, ps1, dir1, ps2, dir2):
    steps = 0

    while True:
        new_ps1 = (ps1[0] + dir1[0], ps1[1] + dir1[1])

        if new_ps1[0] < 0 or new_ps1[0] >= m or new_ps1[1] < 0 or new_ps1[1] >= n:
            dir1 = (-dir1[0], -dir1[1])

        ps1 = new_ps1

        new_ps2 = (ps2[0] + dir2[0], ps2[1] + dir2[1])

        if new_ps2[0] < 0 or new_ps2[0] >= m or new_ps2[1] < 0 or new_ps2[1] >= n:
            dir2 = (-dir2[0], -dir2[1])

        ps2 = new_ps2

        if ps1 == ps2:
            return steps

        steps += 1

    return "never"

m, n = map(int, input().split())
ps1 = tuple(map(int, input().split()))
direction1 = tuple(map(int, input().split()))
ps2 = tuple(map(int, input().split()))
direction2 = tuple(map(int, input().split()))

collision_steps = find_collision_steps(m, n, ps1, direction1, ps2, direction2)
try:
    num = int(collision_steps)
    print(collision_steps + 1, end="")
except:
    print("Never", end="")