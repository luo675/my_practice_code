import torch

X=torch.randn(100,2)

y_true=4*X[:,0:1]-2*X[:,1:2]+3+0.01*torch.randn(100,1)

w=torch.randn(2,1,requires_grad=True)
b=torch.randn(1,requires_grad=True)

for step in range(400):
    y_pred=X@w+b

    loss=((y_pred-y_true)**2).mean()

    loss.backward()

    with torch.no_grad():
        w-=0.01*w.grad
        b-=0.01*b.grad

    w.grad.zero_()
    b.grad.zero_()

    if(step%50==0):
        w_vals=w.flatten().tolist()
        print(f"step {step}:w={w_vals},b={b.item():.3f}")
        
