project = 'JsonType'
copyright = '2024, Cristian Le'
author = 'Cristian Le'

extensions = [
    "myst_parser",
    "sphinx_design",
    "sphinx_togglebutton",
    "sphinx_copybutton",
    "sphinx_prompt",
    "breathe",
    "sphinx.ext.intersphinx",
    "sphinx_tippy",
    "sphinx.ext.todo",
]

templates_path = []
exclude_patterns = [
    'build',
    '_build',
    'Thumbs.db',
    '.DS_Store',
]
source_suffix = [".md"]


html_theme = 'furo'

myst_enable_extensions = [
    "tasklist",
    "colon_fence",
]
myst_heading_anchors = 3

copybutton_exclude = ".linenos, .gp, .go"

todo_include_todos = True
