# text-based--text-editor
Typing is $O(1)$: 
When the user types, characters are inserted into the front of the gap. The gap simply shrinks by one space. No shifting is required.

Deleting is $O(1)$:
Backspacing just expands the gap backwards by one space.

Moving the Cursor is $O(N)$: 
If the user clicks or arrows to a completely different paragraph, the editor must move the gap to the new cursor position. It does this by copying the text between the old cursor and the new cursor across the gap. Because humans type in bursts in a single location, cursor movement is relatively infrequent, making the amortized cost of editing incredibly fast.
