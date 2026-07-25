import numpy as np
import matplotlib.pyplot as plt

np.random.seed(42)

K=10
STEPS=1000
RUNS=2000

def make_bandit(k=K):
    q_star=np.random.normal(loc=0.0,scale=1.0,size=k)
    return q_star

def pull(arm,q_star):
    reward = np.random.normal(loc=q_star[arm],scale=1.0)
    return reward

def select_action(Q,epsilon):
    if np.random.random() < epsilon:
        arm = np.random.randint(0,len(Q))
    else:
        max_q = np.max(Q)
        best_arms=np.where(Q==max_q)[0]

        arm = np.random.choice(best_arms)

    return arm

def run_one_experiment(epsilon,k=K,steps=STEPS):
    q_star = make_bandit(k)
    Q = np.zeros(k)
    N = np.zeros(k)

    optimal_arm = np.argmax(q_star)

    rewards = np.zeros(steps)
    optimal_picks = np.zeros(steps)

    for t in range(steps):
        arm=select_action(Q,epsilon)
        reward = pull(arm,q_star)
        rewards[t] = reward
        optimal_picks[t] = (arm == optimal_arm)

        N[arm] += 1
        Q[arm] +=(1.0/N[arm])*(reward - Q[arm])

    return rewards,optimal_picks

def run_many_experiments(epsilon,runs=RUNS,k=K,steps=STEPS):
    all_rewards = np.zeros((runs,steps))
    all_optimal = np.zeros((runs,steps))

    for run in range(runs):
        r,o = run_one_experiment(epsilon,k,steps)
        all_rewards[run] = r
        all_optimal[run] = o

    avg_rewards = np.mean(all_rewards,axis=0)

    avg_optimal_pct = np.mean(all_optimal,axis=0)*100

    return avg_rewards,avg_optimal_pct

if __name__ == "__main__":
    epsilons = [0 , 0.01, 0.1]
    results = {}

    print("实验开始")

    for eps in epsilons:
        print(f" ε = {eps} ...")
        results[eps] = run_many_experiments(eps)

    print("实验结束")

    plt.figure(figsize=(12,5))

    plt.subplot(1,2,1)

    for eps in epsilons:
        avg_rewards = results[eps][0]
        plt.plot(avg_rewards, label=f"ε = {eps}")

    plt.xlabel("Steps")
    plt.ylabel("Average Reward")
    plt.title("10-Armed Bandit: Average Reward vs Steps")
    plt.legend()
    plt.grid(True,alpha=0.3)

    plt.subplot(1,2,2)
    for eps in epsilons:
        avg_optimal = results[eps][1]
        plt.plot(avg_optimal,label=f"ε = {eps}")
    plt.xlabel("Steps")
    plt.ylabel("% Optimal Action")
    plt.title("10-Armed Bandit: Optimal Action % vs Steps")
    plt.legend()
    plt.grid(True, alpha=0.3)

    plt.tight_layout()
    plt.savefig("mab_results.png", dpi=150)
    plt.show()

    print("搞定！图片已保存为 mab_results.png")    