.. prezento:: CPP - Ll

.. slido::

    digraph foo {
            rankdir=LR;
            node [shape=record];
            a [label="{ <data> 12 | <ref>  }", width=1.2]
            b [label="{ <data> 99 | <ref>  }"];
            c [label="{ <data> 37 | <ref>  }"];
            d [shape=box];
            a:ref:c -> b:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false, arrowsize=1.2];
            b:ref:c -> c:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
            c:ref:c -> d      [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
    }
    digraph foo2 {
            rankdir=LR;
            node [shape=record];
            a [label="{ <data> 12 | <ref>  }"]
            b [label="{ <data> 99 | <ref>  }"];
            c [label="{ <data> 37 | <ref>  }"];
            d [label="{ <data> 37 | <ref> nullptr  }"];

            a:ref -> b:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
            b:ref -> c:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
            c:ref -> d      [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
    }

    digraph foo3 {
            rankdir=LR;
            node [shape=record];
            a [label="{ <data> 12 | <ref>  }"]
            b [label="{ <data> 99 | <ref>  }"];
            c [label="{ <data> 37 | <ref>  }"];
            d [shape=point];

            a:ref -> b:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
            b:ref -> c:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
            c:ref -> d      [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
    }
    digraph foo4 {
            rankdir=LR;
            node [shape=record];
            a [label="{ <data> 12 | <ref>  }"]
            b [label="{ <data> 99 | <ref>  }"];
            c [label="{ <data> 37 | <ref>  }"];
            d [label="{ <data> 37 | <ref> X  }"];

            a:ref -> b:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
            b:ref -> c:data [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
            c:ref -> d      [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];
    }
    digraph ll {
      node [shape=record];
      rankdir=LR;
      edge [tailclip=false];
      l1 [label="{<h> cat |<t>}"];
      l2 [label="{<h> bat |<t>}"];
      l3 [label="{<h> rat |<t>}"];
      null[shape=diamond];
      l1:t -> l2:h [ arrowtail=dot, arrowhead=vee, dir=both ];
      l2:t -> l3:h [ arrowtail=dot, arrowhead=vee, dir=both];
      l3:t -> null:w [arrowtail=dot, arrowhead=vee, dir=both];
    }
    ##https://github.com/msuriar/graphviz/blob/master/horiz-linked-list.dot


    digraph g {
        bgcolor="#BBCAF2";
        label="\nSingle Linked List\n";

        graph[rankdir=LR, center=true, margin=0.2, nodesep=1, ranksep=1]
        edge[arrowsize=1.0, arrowhead=vee]
        node[shape = Mrecord, fontname="Consolas", fontsize=20, width=1, height=1, fixedsize=false];

        list[label = "<name> slist_t | <head> stHead | <tail> *pstTail | uiCount"];
        node0[label = "<name> list_node_t | <next> *pstNext | *pData"];
        node1[label = "<name> list_node_t | <next> *pstNext | *pData"];
        head[label = "pstList"];

        head -> list:name[style=bold, color=red, dir=both, arrowtail=dot];
        list:head:e -> node0:name[dir=forward, arrowtail=normal];
        list:tail:e -> node1:name[dir=both, arrowtail=dot];
        node0:next:e -> list:head:w[dir=both, arrowtail=dot];
        node1:next:e -> list:head:w[dir=both, arrowtail=dot, color=blue, weight=10];
    }


    digraph ll {
      node [shape=record];
      rankdir=LR;
      l1 [label="<h>|<t>"];
      l2 [label="<h>|<t>"];
      l3 [label="<h>|<t>"];
      cat[shape=box];
      bat[shape=box];
      rat[shape=box];
      null[shape=diamond];
      l1:h -> cat;
      l2:h -> bat;
      l3:h -> rat;
      l1:t -> l2:h;
      l2:t -> l3:h;
      l3:t -> null:n;
      { rank = same; l1 l2 l3 null };
    }
    ##https://github.com/msuriar/graphviz/blob/master/vert-linked-list.dot

    digraph ll {
      node [shape=record];
      l1 [label="<h>|<t>"];
      l2 [label="<h>|<t>"];
      l3 [label="<h>|<t>"];
      cat[shape=box];
      bat[shape=box];
      rat[shape=box];
      null[shape=doublecircle];
      l1:h -> cat;
      l2:h -> bat;
      l3:h -> rat;
      l1:t -> l2:h;
      l2:t -> l3:h;
      l3:t -> null;
    }
    ##https://github.com/msuriar/graphviz/blob/master/linked-list.dot
    ##https://stackoverflow.com/questions/29922826/how-to-draw-linked-list-in-graphviz-without-cross-the-node
    ## https://gist.github.com/adamatan/5195647
    ##http://magjac.com/graphviz-visual-editor/
    ##https://stackoverflow.com/questions/70441786/draw-doubly-linked-list-using-graphviz
    ##https://solveforums.msomimaktaba.com/threads/solved-draw-doubly-linked-list-using-graphviz.474481/
    ##graphviz linked list example
    ##dot -Tpng ll.rst > ll.png
