/**
 * Created by liqiusheng on 13/09/2017.
 */

function loadWebAssembly(filename, imports = {}) {
	return fetch(filename)
		.then(response => response.arrayBuffer())
		.then(buffer => WebAssembly.compile(buffer))
		.then(module => {
			imports.env = imports.env || {}
			Object.assign(imports.env, {
				memoryBase: 0,
				tableBase: 0,
				memory: new WebAssembly.Memory({ initial: 256, maximum: 256 }),
				table: new WebAssembly.Table({ initial: 0, maximum: 0, element: 'anyfunc' })
			})
		    console.log(imports)
			return new WebAssembly.Instance(module, imports)
		})
}

function loadJS (url, imports = {}) {
	return fetch(url)
		.then(response => response.text())
		.then(code => new Function('imports', `return (${code})()`))
		.then(factory => ({ exports: factory(imports) }))
}

// Merge 
function instantiate(bytes, imports) {
  return WebAssembly.compile(bytes).then(m => new WebAssembly.Instance(m, imports));
}