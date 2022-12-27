Challenging algorithms and data structures every programmer should try - Austin Z. Henley          

Austin Z. Henley
----------------

I work on AI + dev tools.

[\[email protected\]](/cdn-cgi/l/email-protection#9afbefe9eef3f4f2fff4f6ffe3daf7f3f9e8f5e9f5fceeb4f9f5f7)  
[@austinzhenley](https://twitter.com/austinzhenley)  
[@\[email protected\]](https://hci.social/@azhenley)  
[github/AZHenley](https://github.com/AZHenley)  

* * *

[Home](../index.html) | [Publications](../publications.html) | [Blog](../blog.html)

* * *

Challenging algorithms and data structures every programmer should try
======================================================================

12/21/2022  
  

_See the discussion of this post on [Reddit](https://www.reddit.com/r/programming/comments/zs0git/challenging_algorithms_and_data_structures_every/)._

Alright, so we are all spending our leisure time reading about algorithms, right?

Well, back when I was a student, my algorithms courses regularly put me to sleep. This is unfortunate because there are some _really_ interesting algorithms and data structures out there. Not only have they come up during job interviews, but learning them changed how I think about problems. Plus they're useful even if you don't work on Google-scale problems.

Following my other popular posts, [challenging projects every programmer should try](challengingprojects.html) and [more challenging projects every programmer should try](morechallengingprojects.html), I made a list of interesting algorithms and data structures you should try:

*   Topological sort
*   Recursive descent parsing
*   Myers string difference
*   Bloom filter
*   Piece table
*   Splay tree

**Note:** If you need an introduction to algorithms, I recommend Jeff Erickson's _Algorithms_ ([Amazon](https://amzn.to/3G0v65I), [web](http://jeffe.cs.illinois.edu/teaching/algorithms/?)) or Daniel Zingaro's _Algorithmic Thinking_ ([Amazon](https://amzn.to/3HQYpJk)). If you want a giant reference, then the classic is _Introduction to Algorithms_ by CLRS ([Amazon](https://amzn.to/3hthlDv)). Not enough? Watch MIT's Advanced Data Structures ([YouTube](https://www.youtube.com/playlist?list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf)) to blow your mind.

Topological sort
----------------

Anytime you need to sort items that are dependent on other items, you use topological sort. Common scenarios include determining the order of tasks for build systems, the evaluation order of cells in a spreadsheet, which classes a student should take each semester to graduate, and a variety of scheduling problems.

![](images/toposort.png)

I even used it in graduate school to rearrange graphs to be easier to read.

*   Topological sorting ([Wikipedia](https://en.wikipedia.org/wiki/Topological_sorting))
*   Topological sort interactive visualization ([web](https://www.cs.usfca.edu/~galles/visualization/TopoSortDFS.html))

Recursive descent parsing
-------------------------

This one felt like unlocking a super power when it clicked for me. If you ever need to ingest a recursive data format or make a programming language, this is the tool for you. Sketch out a grammar then map each grammar rule to a code function. Bam! It feels like it codes itself.

![](images/teenyparser.png)

You could have a simple compiler whipped up in a few hours with it.

*   Let's make a Teeny Tiny compiler ([my tutorial series](teenytinycompiler2.html))
*   Crafting Interpreters ([web](https://craftinginterpreters.com/contents.html), [Amazon](https://amzn.to/3HT015y))
*   Recursive descent parser ([Wikipedia](https://en.wikipedia.org/wiki/Recursive_descent_parser))

Myers string diff
-----------------

Processing strings is such a common programming task, but I can usually get away with brute forcing whatever it is I need to calculate. We've all learned about Levenshtein distance, but what if you need to show the differences between two strings in a sensible way?

![](images/codediff.png)

The default algorithm used by git for showing diffs is the Myers diff algorithm.

*   [The Myers diff algorithm](https://blog.jcoglan.com/2017/02/12/the-myers-diff-algorithm-part-1/)
*   [Myers diff algorithm - Code and interactive visualization](https://blog.robertelder.org/diff-algorithm/)

Bloom filter
------------

The most known unknown data structure. In fact, I polled some friends at Big Tech about what data structure they'd suggest I add to this list and _all of them_ said bloom filter!

It really only helps with large-scale problem, such as when you need a really big hash table, but it is a great introduction to _probabilistic data structures_. With very little memory, it can tell you if an item is _not_ present in the table, otherwise it can only tell you _maybe_ the item is present.

Google asked me two interview problems involving these back when I was in college. Have I ever needed this in practice? Nope!

*   Bloom filter ([Wikipedia](https://en.wikipedia.org/wiki/Bloom_filter))
*   Let's implement a bloom filter ([web](https://onatm.dev/2020/08/10/let-s-implement-a-bloom-filter/))
*   Bloom filters by example ([web](https://llimllib.github.io/bloomfilter-tutorial/))

Piece table
-----------

When I first tried making my own text editor, I stored all of the text in an array. But that hits performance problems right away (e.g., when the user inserts text anywhere but the end). Years later I even got asked how to implement a performant text buffer at an internship interview.

What should I have used? Well, there are a few options with different tradeoffs: rope, gap buffer, or piece table. With a piece table, you track the edits performed on text rather than only keeping the resulting text. It makes a lot of other features trivial to add (e.g., undo support and incremental saving).

Piece tables aren't only useful for text editors though. You can use it whenever you have a large buffer of data that can be arbitrarily modified.

*   Piece table ([Wikipedia](https://en.wikipedia.org/wiki/Piece_table))
*   VS Code's text buffer story ([web](https://code.visualstudio.com/blogs/2018/03/23/text-buffer-reimplementation))
*   The piece table ([web](https://darrenburns.net/posts/piece-table/))

Splay tree
----------

How about a self-optimizing data structure? Splay trees are binary trees that will tend to have the more recently accessed elements closer to the root, and it does so without maintaining any additional metadata. Each time an element is accessed, it gets moved to the root.

![](images/algorithmsbook.jpg)

It's a tree with a builtin cache and it is beautifully simple to implement! As a student, I had a really hard time implementing red-black trees (we wrote the code on paper, ugh) so I was pleasantly surprised when splay trees just clicked for me.

*   Splay tree interactive visualization ([web](https://www.cs.usfca.edu/~galles/visualization/SplayTree.html))
*   Splay tree ([Wikipedia](https://en.wikipedia.org/wiki/Splay_tree))
*   Implementation in TypeScript ([GitHub](https://github.com/w8r/splay-tree))

* * *

If you are still craving more, here are the honorable mentions that I cut from the list:

*   Trie
*   Segment tree
*   Operational transformation
*   Fibonacci heap
*   Skip list
*   Union find

Try these out, and let me know if I missed any!