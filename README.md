# Simple Lexer/Parser for &lt;expr&gt; Grammar 🪄

The grammar rules are as follows:

<code>
&lt;assign&gt; -&gt; &lt;id&gt; = &lt;expr&gt;
</code>
<br>
<code>
&lt;expr&gt; -&gt; &lt;term&gt; {+ &lt;term&gt;}
</code>
<br>
<code>
&lt;term&gt; -&gt; &lt;factor&gt; {* &lt;factor&gt;}
</code>
<br>
<code>
&lt;factor&gt; -&gt; ( &lt;expr&gt; ) | &lt;id&gt; | &lt;num&gt;
</code>
<br>
<code>
&lt;id&gt; -&gt; a | b | c | ... | z
</code>
<br>
<code>
&lt;num&gt; -&gt; 0 | 1 | 2 | ...
</code>
