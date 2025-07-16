# Split a Circular Linked List

## Statement

Given a circular linked list, `list`, of positive integers, split it into two circule linked lists. The first circular linked list should contain the first half of the nodes (exactly `[list.length / 2]` nodes) in the same order they appeared in the original list, while the second circular linked list should include the remaining nodes in the same order.

Return an array, `answer`, of length 2, where:
- `answer[0]` is the head of the circular linked list representing the first half.
- `answer[1]` is the head of the circular linked list representing the second half/

> **Note:** A circular linked list is a standard linked list where the last node points back to the first node.

## Approach

1. Initialize the `slow` and `fast` pointers to the `head` of the list. The `slow` pointer moves one node at a time while the `fast` pointer moves two nodes at a time.
2. iterate through the list using the `fast` and `slow` pointers until the `fast` pointer has reached back to the `head`, ensured by the conditions `fast->next != head` and `fast->next->next != head`.
3. After iterating, the `slow` pointer will be at the middle point of the list, while the `fast` pointer will be pointing back to the `head`. This middle point node serves as the point where we will split the list into two halves.
4. the first circular linked list will start from the original head (`head2 = head`). Before modifying `slow->next`, store `slow->next` in `head2` to retain the starting node of the second half. Then update `slow->next` to point back to `head1`, effectively closing the first circular half.
5. The second half of the list begins from the node immediately following the middle point, which we stored in `head2` in the previous step. This prevents losing the regerence to the second half's start after updating `slow->next` for the first half.
6. Next, ensure that the second half is also circular. Traverse the second half starting from `head2` using the `fast` pointer. The `fast` pointer moves throughout the list until `fast->next` points back to the `head`.
7. Once the `fast->next` pointer reaches the `head`, update `fast->next=head2`, closing the second circular list.
8. Return the heads of the two split circular linked lists as an array: `[head1, head2]`.

## Visualization

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/cd017097-3aac-4702-9d7b-3a6e2cca0bf6" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/e874b2fc-bd3b-4012-8b65-89a0e856e7fd" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/bef3f4fa-ddea-490b-a835-13f4cf75e268" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/1d51a43c-cb44-463b-9705-017fc0267d97" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/7eb9e219-a6a4-471a-baa3-40ab3506ebd0" />

<img width="934" height="512" alt="image" src="https://github.com/user-attachments/assets/15c2a539-914b-4dff-9c9a-cc5ec09e2e61" />

<img width="932" height="512" alt="image" src="https://github.com/user-attachments/assets/4250d026-768f-46b6-9f4f-4ae5895b4220" />

<img width="933" height="511" alt="image" src="https://github.com/user-attachments/assets/6815a56d-b885-4e89-8a2a-9316489aa42a" />

## Time Complexity

The time complexity is $O(n)$, where $n$ is the total number of nodes in the circular linked list. This is because there are two passes over the list $\textemdash$ one to count the nodes and another to split the list.

## Space Complexity

The space complexity is $O(1)$ because the solution uses constant space regardless of the input size.
