import gymnasium as gym

env=gym.make("CartPole-v1",render_mode="human")

for episode in range(3):
    state, info =env.reset()
    total_reward=0
    done=False

    while not done:
        action=env.action_space.sample()
        state,reward,done,truncated,info=env.step(action)
        total_reward += reward

    print(f"第{episode+1}局:撑了{total_reward}步")

env.close()

