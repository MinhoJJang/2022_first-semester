# 0427 Quiz & Debate

## 1. Explain how the Semaphore prevents busy waiting.

Using Block Operation, when block(); operation is excuted, add the process to waiting queue.

## 2. In class we discussed Incorrect use of semaphore operations: (i) signal .... wait, (ii) wait ... wait, (iii) Omitting of wait or signal (or both). Explain what happens in each case

1. No mutual exclusion!
2. No Progress!
3. No mutual exclusion, or Progress, or both.
   - no wait : No mutual exclusion
   - no signal : No progress
   - no both : No both

## 3. Explain why priority inversion happens, and how we can solve it.

Let me call three process, L, M, H(Low, Middle, High) and it shows the priority of process. When L is currently using the CS part that protected with Semaphore,

## 4. Explain the readers-writers problem. Use Figure in next-page to explain. Use semaphores wrt, mutex and integer readcount. Consider the following cases where R1, R2 are readers and W1, W2 are writers. (Ent) means enter, (Exit) means exit.

```
(1) W1 (Ent) → W2 (Ent) → W1 (Exit) → W2 (Exit)
(2) R1 (Ent) → R2 (Ent) → W1 (Ent)→ R1 (Exit) → R2 (Exit) → W1 (Exit)
(3) W1 (Ent) → R1 (Ent) → R2 (Ent) → W1 (Exit) → R1 (Exit) → R2 (Exit)
```
