//db.Cookbook.find({title: {'$regex': /^p/i}});
//db.Cookbook.find({title: {'$regex': /^e/i}});
//db.Cookbook.find({title: {'$regex': 'e'}}, {"step.description": /a/});
//db.Cookbook.find({$or:[{title: {'$regex': 'e'}}, {"step.description": /a/}]});

//db.Cookbook.find({"ingredients.name": "eggs"});
//db.Cookbook.find({$nor: [{"ingredients.name": "eggs"}]})
//db.Cookbook.find({$and: [{"ingredients.name": "eggs"}, {"ingredients.name": "sugar"}]})
//db.Cookbook.find({$or: [{"ingredients.name": "eggs"}, {"ingredients.name": "sugar"}]})
//db.Cookbook.count({ingredients: {$size: 3}})

// db.Cookbook.aggregate([
//     {$match:{"category.0" : "Dessert"}},
//     {$group: {_id: null, count: {$sum: 1}}}
//     ])
//     

// db.Cookbook.aggregate([
//     {$match:{"category.0" : "breakfast"}},
//     {$group: {_id: null, count: {$sum: 1}}}
//     ])
// 

// db.Cookbook.aggregate([
//     {$match:{"category.0" : "main course"}},
//     {$group: {_id: null, count: {$sum: 1}}}
//     ])

// db.Cookbook.aggregate([
//     {$match:{"category.0" : "snack"}},
//     {$group: {_id: null, count: {$sum: 1}}}
//     ])

// db.Cookbook.aggregate([
//     {$match:{"category.0" : "starter"}},
//     {$group: {_id: null, count: {$sum: 1}}}
//     ])
// 